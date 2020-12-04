def tuple_sum(tup):
    if isinstance(tup, int):
        return tup
    else:
        accum = 0
        for element in tup:
            accum += tuple_sum(element)
    return accum


def product_set(set1, set2):
    res = set()
    for i in set1:
        for j in set2:
            res = res | {(i, j)}
    return res


case = {1, 2, 3, 4, 5, 6}
case2 = product_set(case, case)
case3 = product_set(case, case2)

case_sum = [tuple_sum(tup) for tup in case3]


def prob_over(x):
    ans = 0
    for j in range(0, len(case_sum)):
        if case_sum[j] >= x:
            ans += 1
    return ans / 216 * 100


print(prob_over(4))
