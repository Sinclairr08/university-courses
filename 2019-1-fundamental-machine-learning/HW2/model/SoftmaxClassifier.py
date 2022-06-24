import numpy as np

class SoftmaxClassifier:
    def __init__(self, num_features, num_label):
        self.num_features = num_features
        self.num_label = num_label
        self.W = np.zeros((self.num_features, self.num_label))

    def train(self, x, y, epochs, batch_size, lr, optimizer):
        """
        N : # of training data
        D : # of features
        C : # of classes

        [INPUT]
        x : (N, D), input data (first column is bias for all data)
        y : (N, )
        epochs: (int) # of training epoch to execute
        batch_size : (int) # of minibatch size
        lr : (float), learning rate
        optimizer : (Python class) Optimizer

        [OUTPUT]
        final_loss : (float) loss of last training epoch

        [Functionality]
        Given training data, hyper-parameters and optimizer, execute training procedure.
        Training should be done in minibatch (not the whole data at a time)
        Procedure for one epoch is as follow:
        - For each minibatch
            - Compute probability of each class for data
            - Compute softmax loss
            - Compute gradient of weight
            - Update weight using optimizer
        * loss of one epoch = Mean of minibatch losses
        (minibatch losses = [0.5, 1.0, 1.0, 0.5] --> epoch loss = 0.75)

        """
        print('========== TRAINING START ==========')
        final_loss = None   # loss of final epoch
        num_data, num_feat = x.shape
        losses = []
        for epoch in range(1, epochs + 1):
            batch_losses = []   # list for storing minibatch losses

        # ========================= EDIT HERE ========================
            index = 0

            while index < num_data:
                # Selects the minibatch size
                data = x[index: min(index + batch_size, num_data)]
                label = y[index: min(index + batch_size, num_data)]
                index += batch_size

                prob = self._softmax(np.matmul(data, self.W))               # Calculate softmax
                loss = self.softmax_loss(prob, label)                       # Calculate loss using softmax value
                grad_weight = self.compute_grad(data, self.W, prob, label)  # Calculate gradient of weight using softmax value


                self.W = optimizer.update(self.W, grad_weight, lr)      # Update weight using given optimizer
                batch_losses.append(loss)                               # Save each batch losses

        # ============================================================
            epoch_loss = sum(batch_losses) / len(batch_losses)  # epoch loss
            # print loss every 10 epoch
            if epoch % 10 == 0:
                print('Epoch %d : Loss = %.4f' % (epoch, epoch_loss))
            # store losses
            losses.append(epoch_loss)
        final_loss = losses[-1]

        return final_loss

    def eval(self, x):
        """

        [INPUT]
        x : (N, D), input data

        [OUTPUT]
        pred : (N, ), predicted label for N test data

        [Functionality]
        Given N test data, compute probability and make predictions for each data.
        """
        pred = None
        # ========================= EDIT HERE ========================

        # Calculate the softmax value of total data
        pred = np.array([])
        softval = self._softmax(np.matmul(x, self.W))

        # For each data, select one which has max probability
        for i in range(len(softval)):
            pred = np.append(pred, np.argmax(softval[i]))

        # ============================================================
        return pred

    def softmax_loss(self, prob, label):
        """
        N : # of minibatch data
        C : # of classes

        [INPUT]
        prob : (N, C), probability distribution over classes for N data
        label : (N, ), label for each data

        [OUTPUT]
        softmax_loss : scalar, softmax loss for N input

        [Functionality]
        Given probability and correct label, compute softmax loss for N minibatch data
        """
        softmax_loss = 0.0
        # ========================= EDIT HERE ========================

        len_data, _ = prob.shape

        # For each data, calculate negative log likelihood (NLL)
        for i in range(len_data):
            softmax_loss -= np.log(prob[i][label[i]])

        # ============================================================
        return softmax_loss

    def compute_grad(self, x, weight, prob, label):
        """
        N : # of minibatch data
        D : # of features
        C : # of classes

        [INPUT]
        x : (N, D), input data
        weight : (D, C), Weight matrix of classifier
        prob : (N, C), probability distribution over classes for N data
        label : (N, ), label for each data. (0 <= c < C for c in label)

        [OUTPUT]
        gradient of weight: (D, C), Gradient of weight to be applied (dL/dW)

        [Functionality]
        Given input (x), weight, probability and label, compute gradient of weight.
        """
        grad_weight = np.zeros_like(weight, dtype=np.float32) # (D, C)
        # ========================= EDIT HERE ========================

        grad_weight = np.transpose(grad_weight)                                      # (C, D)
        len_data, _ = x.shape

        for data_i in range(len_data):                                              # For each data
            for label_j in range(self.num_label):                                   # For each label
                if label[data_i] == label_j:                                        # Gradient for right label
                    gradient = np.multiply(prob[data_i][label_j] - 1, x[data_i])
                else:                                                               # Gradient for wrong label
                    gradient = np.multiply(prob[data_i][label_j], x[data_i])

                grad_weight[label_j] += gradient                                     # Add the gradient value

        grad_weight = np.divide(grad_weight, len_data)                               # Divide by the size of data
        grad_weight = np.transpose(grad_weight)                                      # (D, C)

        # ============================================================
        return grad_weight


    def _softmax(self, x):
        """
        [INPUT]
        x : (N, C), score before softmax

        [OUTPUT]
        softmax : (same shape with x), softmax distribution over axis-1

        [Functionality]
        Given an input x, apply softmax function over axis-1 (classes).
        """
        softmax = None
        # ========================= EDIT HERE ========================

        num_data, _ = x.shape
        softmax = []

        # For each data, calculate the softmax value and append to softmax list
        for i in range(num_data):
            vector = np.exp(x[i])
            vector = np.divide(vector, np.sum(vector))                              # Normalize
            softmax.append(vector)

        softmax = np.asarray(softmax)

        # ============================================================
        return softmax