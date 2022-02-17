'''
Knap sack: Given a knapsack with a specific carrying capacity (W), help Bob determine 
           the maximum value he can get from the items in the house. 
           Note that Bob can take only one of each item.

@Andrea-Tomatis
'''

def ord_function(e):
    return e['value']

def max_value(items, limit):
    sum_value = 0
    sum_weight = 0
    items.sort(key = ord_function)
    items.reverse()
    for i in items:
        if sum_weight + i['weight'] <= limit:
            sum_weight += i['weight']
            sum_value += i['value']
        if sum_weight == limit:
            break
        
    return sum_value



def main():
    items = [{ "weight": 5, "value": 10 }, 
            { "weight": 4, "value": 40 }, 
            { "weight": 6, "value": 30 }, 
            { "weight": 4, "value": 50 }]
    limit = 10

    print(max_value(items, limit))


if __name__ == '__main__':
    main()