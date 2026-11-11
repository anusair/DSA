class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        mn = min(need1 , need2)
        subtotal = costBoth * mn
        if costBoth > cost2 + cost1:
            return cost2 * need2 + cost1 * need1
        else: 
            if mn == need1:
                return subtotal + min(costBoth , cost2) * (need2 - need1)
            else: return subtotal + min(costBoth , cost1) * (need1 - need2)