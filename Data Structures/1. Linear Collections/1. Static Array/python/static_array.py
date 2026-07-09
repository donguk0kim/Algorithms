class StaticArray:

    # This class just dumbs down a regular array to be statically sized.

    def __init__(self, size: int):
        self.size = size
        self._store = [0] * size

    # O(1)
    def __getitem__(self, index):
        self._store[index]
        
    # O(1)
    def __setitem__(self, index, value):
        self._store[index] = value

    def __check_index(self, index):
        if index >= self.size:
            raise "index out of bounds"
