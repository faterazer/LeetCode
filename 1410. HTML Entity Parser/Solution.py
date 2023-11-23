class Solution:
    def entityParser(self, text: str) -> str:
        return (
            text.replace("&quot;", '"')
            .replace("&apos;", "'")
            .replace("&gt;", ">")
            .replace("&lt;", "<")
            .replace("&frasl;", "/")
            .replace("&amp;", "&")
        )
