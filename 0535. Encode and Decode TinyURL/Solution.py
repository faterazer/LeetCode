import string
import random


class Codec:
    def __init__(self) -> None:
        self.candidates = string.ascii_lowercase + string.ascii_uppercase + string.digits
        self.code2url = {}

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        key = []
        while ''.join(key) in self.code2url:
            idx = random.randrange(len(self.candidates))
            key.append(self.candidates[idx])
        key = ''.join(key)
        self.code2url[key] = longUrl
        return 'http://tinyurl.com/' + key

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        key = shortUrl.split('/')[-1]
        return self.code2url[key]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
