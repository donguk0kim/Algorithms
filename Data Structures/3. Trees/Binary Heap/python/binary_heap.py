import math

class BinaryMinHeap:

    def __init__(self):
        self.store = [-math.inf]

    def size(self) -> int:
        return len(self.store) - 1
    
    def min(self) -> int:
        return self.store[1]
    
    def max(self) -> int:
        return self.store[self.size()]
    
    def insert(self, value: int):
        # append to store
        # percolate up to the right place
        pass
    
    def pop(self) -> int:
        # delete max from store
        # replace min with max
        # percolate down to the right place
            # find the mininum and put it at the root
        pass

    def heapify_up(self, values: list[int]):
        pass

