import numpy as np
from utils.utils_Answer import Gaussian_prob

Heart_Category_feature_idx = [1, 2, 5, 6, 8, 10, 11, 12]
Carseats_Category_feature_idx = [6, 9]
Tennis_Category_feature_idx = [0, 1, 2, 3]


class Gaussian_NaiveBayesian():

    def __init__(self):
        pass

    def fit(self, dataFrame, data_name):
        self.df = dataFrame
        self.data_name = data_name
        self.Category_feature_idx = (data_name == 'Heart') \
                                    and Heart_Category_feature_idx or \
                                    (data_name == 'Carseats') \
                                    and Carseats_Category_feature_idx \
                                    or Tennis_Category_feature_idx

        header = self.df.columns.values
        input_feature = header[:-1]
        output_feature = header[-1]

        Y_data = self.df[output_feature]

    # Data split to 'Class = Yes' data and 'Class = No' data.

        pos_idx = (Y_data == 'Yes')

        pos_data = self.df[pos_idx]
        neg_data = self.df[~pos_idx]

    # P(Yes), P(No)
      # ======     Edit this    ======
        self.prob_yes = len(pos_data) / (len(pos_data) + len(neg_data))
        self.prob_no = len(neg_data) / (len(pos_data) + len(neg_data))
      # ==============================

    # P(X | Yes), P(X | No)
        self.prob_given_yes = {}
        self.prob_given_no = {}

    # To deal with avoid zero probability,
    # Save the numbers of Category for each column. (only Category Feature)
        self.num_of_attr = [ 0 ] * len(input_feature)


    # Setting P(x_i | Yes)
      # To prevent key error, predefine the all dictionary to 0.
        self.initialize_likelihood_prob(self.prob_given_yes)
        self.set_likelihood_prob(pos_data, self.prob_given_yes)

    # Setting P(x_i | No)
      # To prevent key error, predefine the all dictionary to 0.
        self.initialize_likelihood_prob(self.prob_given_no)
        self.set_likelihood_prob(neg_data, self.prob_given_no)

    def initialize_likelihood_prob(self, likelihood):
        data = self.df
        header = data.columns.values
        input_feature = header[:-1]

        for idx, f in enumerate(input_feature):
        # To prevent the key error, Firstly, posterior ( p(x_i | class) ) initialize to 0
            col_data = data[f]

            if idx in self.Category_feature_idx:
                attribute = np.unique(col_data)
                self.num_of_attr[idx] = len(attribute)

                for attr in attribute:
                    if type(attr) == np.float64:
                        attr = str(int(attr))
                    likelihood['%s = %s' %(f, attr)] = 0

        return

    def set_likelihood_prob(self, data, likelihood):
        '''
        In this function, the process for assigning the probability of likelihood
        is done. Because likelihood is managed by dictiorary, you should be careful to the key.
        the key format of Category feature is 'feature_name = value' ('outlook =  sunny')
        and the Numeric is "'feautre_name'_mean" and "'feature_name_std'" ('Age_mean', 'Age_std')

        (Important!) Keep in mind that we use Laplacian correction.

        ??? ??????????????? likelihood ?????? ?????? ???????????? ????????? ???????????????.
        likelihood??? dictionary ????????? ???????????? key ?????? ??????????????? ????????????.
        Category data??? key ?????? 'feature??????  = ???' ('outlook =  sunny')
        Numeric data??? 'feature??????_mean', 'feature??????_std' ?????????.

        (??????!) ????????? Laplacian correction??? ???????????? ????????? ????????? ???????????????!

        Category: likelihood['%s = %s' %(feature_name, value)] =  ?
        Numeric:  likelihood['%s_mean' %(feature_name)] =  ?
        Numeric:  likelihood['%s_std' %(feature_name)] =  ?

        [Parameter]
            data : [dataFrame] label is 'Yes' data  xor 'No' data
            likelihood : [dictionary] likelihood probability. (don't overwritten!)

        [return]
            nothing

        '''
        n = len(data)
        input_feature = data.columns.values[:-1]

        # ==========       Edit here         =============
        for idx, f in enumerate(input_feature):
            column_data = data[f]

            if idx in self.Category_feature_idx:
                attribute, count = np.unique(column_data, return_counts=True)

                for attr, cnt in zip(attribute, count):
                  # to avoid key Error in predict fuction.
                    if type(attr) == np.float64 or type(attr) == np.float32:
                        attr = str(int(attr))
                    likelihood['%s = %s' %(f, attr)] = round((cnt + 1) / (sum(count) + len(count)), 6)
            else:
                likelihood['%s_mean' %(f)] =  np.mean(column_data)
                likelihood['%s_std' %(f)] =  np.std(column_data)
        # ================================================
        return


    def predict(self, Test_x):
        pred = np.full(len(Test_x), None)

        for i, idx in enumerate(Test_x.index):
            row = Test_x.loc[idx]
            Yes_posterior = self.get_posterior(row, self.prob_given_yes, self.prob_yes)
            No_posterior = self.get_posterior(row, self.prob_given_no, self.prob_no)

            if Yes_posterior < No_posterior:
                pred[i] = 'No'
            else:
                pred[i] = 'Yes'
        return pred


    def get_posterior(self, tuple, likelihood, prior):
        '''
        In this function return the posterior probability to use maximum a posterior.
        (posterior ??? likelihood x prior)
        we will use the likelihood and prior instead of accurate posterior.
        your work is return the posterior for given tuple.
        Gaussian prob function is defined at utils.utils_Answer.py

        Keep in mind that if dictionary value is undefined before, the value is 0.

        ??? ????????? posterior ????????? ???????????? ???????????????.
        ???????????? posterior??? ????????? ??? ?????? likelihood ??? prior??? ???????????????.
        ???????????? ????????? ????????? ????????? tuple data??? ????????? posterior??? ???????????? ????????? ???????????? ????????????.
        Gaussian prob function??? utils.utils_Answer.py??? ???????????? ????????????.

        dictionary ?????? ????????? ???????????? ???????????? value ??? 0?????? ???????????????.

        [ Parameter ]
            tuple : one data [1 x (D-1) Dataframe] : a data tuple (exclueded output part)
            likelihood [dictionary] : a dictionary for likelihood
            prior [float] : probability in [0, 1]

        [return]
            posterior [float] : a probability of posterior.
        '''
        feature = tuple.index
        posterior = 1

        # ============            Edit here              ===============
        for idx, f in enumerate(feature):
            val = tuple[f]

            if idx in self.Category_feature_idx:
              # to avoid key Error in predict fuction.
                if type(val) == np.float64 or type(val) == np.float32:
                    val = int(val)
                posterior *= likelihood['%s = %s' %(f, val)]

            else:
                mean = likelihood['%s_mean' % (f)]
                std = likelihood['%s_std' % (f)]
                posterior *= Gaussian_prob(val, mean= mean, std= std)

        posterior *= prior

        # ===============================================================
        return posterior
