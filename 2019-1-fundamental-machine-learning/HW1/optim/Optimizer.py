import numpy as np

"""
DO NOT EDIT ANY PARTS OTHER THAN "EDIT HERE" !!! 

[Description]
__init__ - Initialize necessary variables for optimizer class
input   : gamma, epsilon
return  : X

update   - Update weight for one minibatch
input   : w - current weight, grad - gradient for w, lr - learning rate
return  : updated weight 
"""

class SGD:
    def __init__(self, gamma, epsilon):
        # ========================= EDIT HERE =========================
        self.gamma = gamma
        self.epsilon = epsilon

        # =============================================================

    def update(self, w, grad, lr):
        updated_weight = None
        # ========================= EDIT HERE =========================

        updated_weight = w - lr * grad

        # =============================================================
        return updated_weight

class Momentum:
    def __init__(self, gamma, epsilon):
        # ========================= EDIT HERE =========================
        self.gamma = gamma
        self.epsilon = epsilon
        self.velocity = []

        # =============================================================

    def update(self, w, grad, lr):
        updated_weight = None
        # ========================= EDIT HERE =========================

        if len(self.velocity) == 0:
            self.velocity = lr * grad

        else:
            self.velocity = self.gamma * self.velocity + lr * grad

        updated_weight = w - self.velocity

        # =============================================================
        return updated_weight


class RMSProp:
    # ========================= EDIT HERE =========================
    def __init__(self, gamma, epsilon):
        # ========================= EDIT HERE =========================
        self.gamma = gamma
        self.epsilon = epsilon
        self.G = []

        # =============================================================

    def update(self, w, grad, lr):
        updated_weight = None
        # ========================= EDIT HERE =========================

        if len(self.G) == 0:
            self.G = np.power(grad, 2)

        else:
            self.G = self.gamma * self.G + (1 - self.gamma) * np.power(grad, 2)

        eps = np.asarray([self.epsilon] *len(self.G))
        eps = eps.reshape(len(grad), 1)

        updated_weight = np.sqrt(self.G  + eps)
        updated_weight = np.divide(updated_weight, lr)
        updated_weight = np.reciprocal(updated_weight)
        updated_weight = np.multiply(updated_weight, grad)
        updated_weight = w - updated_weight

        # =============================================================
        return updated_weight