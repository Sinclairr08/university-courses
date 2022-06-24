import numpy as np

class LinearRegression:
    def __init__(self, num_features):
        self.num_features = num_features
        self.W = np.zeros((self.num_features, 1))

    def train(self, x, y, epochs, batch_size, lr, optim):
        final_loss = None   # loss of final epoch

        # Training should be done for 'epochs' times with minibatch size of 'batch_size'
        # The function 'train' should return the loss of final epoch
        # Loss of an epoch is calculated as an average of minibatch losses

        # ========================= EDIT HERE ========================

        # Shuffle the data
        len_data = len(x)
        perm = np.random.permutation(len_data)

        x = x[perm]
        y = y[perm]

        #Training for epoch times
        for epoch in range(epochs):
            batch_loss = 0
            index = 0

            # For each batch
            while index < len_data:
                loss = 0
                grad = []                           # Store the gradient as a list

                # For each elements in a batch
                for i in zip(x[index : min(index + batch_size, len_data)], y[index : min(index + batch_size, len_data)]):
                    data, label = i
                    loss += np.sum(np.power(np.matmul(data, self.W) - label, 2))
                    grad.append(np.multiply(np.matmul(data, self.W) - label, data))

                index += batch_size

                # Randomly choose a gradient
                np.random.shuffle(grad)
                grad = grad[0]
                grad = np.asarray(grad)
                grad = grad.reshape(len(grad), 1)

                self.W = optim.update(self.W, grad, lr)
                batch_loss += loss

        # Final loss is the average of batch loss of final epoch
        final_loss = batch_loss / len_data

        # ============================================================
        return final_loss

    def eval(self, x):
        pred = None

        # Evaluation Function
        # Given the input 'x', the function should return prediction for 'x'

        # ========================= EDIT HERE ========================

        pred = np.matmul(x, self.W)
        pred.shape = (pred.shape[0], 1)

        # ============================================================
        return pred


