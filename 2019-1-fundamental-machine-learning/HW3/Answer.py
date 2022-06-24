import numpy as np

def Accuracy(label, pred):
    ########################################################################################
    # TODO : Complete the code to calculate the accuracy for prediction.
    #         [Input]
    #         - label : (N, ), Correct label with 0 (negative) or 1 (positive)
    #         - hypo  : (N, ), Predicted score between 0 and 1
    #         [output]
    #         - Acc : (scalar, float), Computed accuracy score
    # ========================= EDIT HERE =========================
    total = len(label)
    correct = len(np.where(label == pred)[0])
    Acc = correct / total
    # =============================================================
    return Acc

def Precision(label, pred):
    ########################################################################################
    # TODO : Complete the code to calculate the Precision for prediction.
    #         you should consider that label = 1 is positive. 0 is negative
    #         Notice that, if you encounter the divide zero, return 1
    #         [Input]
    #         - label : (N, ), Correct label with 0 (negative) or 1 (positive)
    #         - hypo  : (N, ), Predicted score between 0 and 1
    #         [output]
    #         - precision : (scalar, float), Computed precision score
    # ========================= EDIT HERE =========================
    true_pred = np.where(pred == 1)[0]
    true_total = len(true_pred)

    if true_total == 0:
        precision = 1

    else:
        true_correct = 0

        for ind in true_pred:
            if label[ind] == 1:
                true_correct += 1

        precision = true_correct / true_total
   # =============================================================
    return precision

def Recall(label, pred):
    ########################################################################################
    # TODO : Complete the code to calculate the Recall for prediction.
    #         you should consider that label = 1 is positive. 0 is negative
    #         Notice that, if you encounter the divide zero, return 1
    #         [Input]
    #         - label : (N, ), Correct label with 0 (negative) or 1 (positive)
    #         - hypo  : (N, ), Predicted score between 0 and 1
    #         [output]
    #         - recall : (scalar, float), Computed recall score
    # ========================= EDIT HERE =========================
    true_label = np.where(label == 1)[0]
    true_total = len(true_label)

    if true_total == 0:
        recall = 1

    else:
        true_correct = 0
        for ind in true_label:
            if pred[ind] == 1:
                true_correct += 1

        recall = true_correct / true_total
    # =============================================================
    return recall

def F_measure(label, pred):
    ########################################################################################
    # TODO : Complete the code to calculate the F-measure score for prediction.
    #         you can erase the code. (F_score = 0.)
    #         Notice that, if you encounter the divide zero, return 1
    #         [Input]
    #         - label : (N, ), Correct label with 0 (negative) or 1 (positive)
    #         - hypo  : (N, ), Predicted score between 0 and 1
    #         [output]
    #         - F_score : (scalar, float), Computed F-score score
    # ========================= EDIT HERE =========================
    rec = Recall(label, pred)
    prec = Precision(label, pred)

    if rec + prec == 0:
        F_score = 1
    else:
        F_score = (2 * rec * prec) / (rec + prec)
    # =============================================================
    return F_score

def MAP(label, hypo, at = 10):
    ########################################################################################
    # TODO : Complete the code to calculate the MAP for prediction.
    #         Notice that, hypo is the real value array in (0, 1)
    #         MAP (at = 10) means MAP @10
    #         [Input]
    #         - label : (N, K), Correct label with 0 (incorrect) or 1 (correct)
    #         - hypo  : (N, K), Predicted score between 0 and 1
    #         - at: (int), # of element to consider from the first. (TOP-@)
    #         [output]
    #         - Map : (scalar, float), Computed MAP score
    # ========================= EDIT HERE =========================
    query_num, query_len = label.shape

    rel_num = [0] * query_num
    ap = [0] * query_num

    for query in range(query_num):
        rel_num[query] = len(np.where(label[query] == 1)[0])

        pred = np.zeros_like(label[0], dtype=float)
        label_rearr = []

        sorted_ind = np.flip(np.asarray(hypo[query]).argsort())

        for ind in sorted_ind:
            label_rearr.append(label[query][ind])

        for ind in range(at):
            pred[ind] = 1

        for ind in range(at):
            if label_rearr[ind] == 1:
                ap[query] += Precision(label_rearr[:ind+1], pred[:ind+1])

        ap[query] /= rel_num[query]

    Map = np.average(ap)
    # =============================================================
    return Map

def nDCG(label, hypo, at = 10):
    ########################################################################################
    # TODO : Complete the each code to calculate the nDCG for prediction.
    #         you can erase the code. (dcg, idcg, ndcg = 0.)
    #         Notice that, hypo is the real value array in (0, 1)
    #         nDCG (at = 10 ) means nDCG @10
    #         [Input]
    #         - label : (N, K), Correct label with 0 (incorrect) or 1 (correct)
    #         - hypo  : (N, K), Predicted score between 0 and 1
    #         - at: (int), # of element to consider from the first. (TOP-@)
    #         [output]
    #         - Map : (scalar, float), Computed nDCG score


    def DCG(label, hypo, at=10):
        # ========================= EDIT HERE =========================
        dcg = 0

        sorted_ind = np.flip(np.asarray(hypo).argsort())
        label_rearr = []

        for ind in sorted_ind:
            label_rearr.append(label[ind])

        label_rearr = label_rearr[:at]

        for i in range(len(label_rearr)):
            if label_rearr[i] == 1:
                dcg += 1 / np.log2(i + 2)

        # =============================================================
        return dcg

    def IDCG(label, hypo, at=10):
        # ========================= EDIT HERE =========================
        idcg = 0

        ideal_label = np.zeros_like(label)
        cnt = len(np.where(label == 1)[0])

        for i in range(cnt):
            ideal_label[i] += 1

        ideal_label = ideal_label[:at]

        for i in range(len(ideal_label)):
            if ideal_label[i] == 1:
                idcg += 1 / np.log2(i + 2)

        # =============================================================
        return idcg
    # ========================= EDIT HERE =========================
    ndcg = 0
    query_num, query_len = label.shape

    for query in range(query_num):
        ndcg_query = DCG(label[query], hypo[query], at) / IDCG(label[query], hypo[query], at)
        ndcg += ndcg_query

    ndcg /= query_num

    # =============================================================
    return ndcg

# =============================================================== #
# ===================== DO NOT EDIT BELOW ======================= #
# =============================================================== #

def evaluation_test1(label, pred, at = 10):
    result = {}

    result['Accuracy '] = Accuracy(label, pred)
    result['Precision'] = Precision(label, pred)
    result['Recall   '] = Recall(label, pred)
    result['F_measure'] = F_measure(label, pred)

    return result

def evaluation_test2(label, hypo, at = 10):
    result = {}

    result['MAP  @%d'%at] = MAP(label, hypo, at)
    result['nDCG @%d'%at] = nDCG(label, hypo, at)

    return result
