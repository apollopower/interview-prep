class LFU_Cache():
    def __init__(self, size):
        self.size = size
        self.cache = {}

    def set(self, key, value):
        if len(self.cache) == self.size:
            pass
            # Do thing here to remove least used thing
        self.cache[key] = value

    def get_item(self, key):
        return self.cache

cache = LFU_Cache(5)

cache.set('hello', 1)
cache.set('jonas', 3)

result = cache.get_item('jonas')

print(result)

