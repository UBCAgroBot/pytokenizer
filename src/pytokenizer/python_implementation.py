# sample text
text = "Hello, world! This is a test sentence for a tokenizer. It includes numbers like 123.45, special characters (@#$), and a contraction (don't)."

tokens = text.encode("utf-8")
tokens = list(map(int, tokens))

def get_stats(ids):
    counts = {}
    for pair in zip(ids, ids[1:]):
        counts[pair] = counts.get(pair, 0) + 1
    return counts

stats = get_stats(tokens) # {(72, 101): 1, ...}

top_pair = max(stats, key = stats.get)

def merge(ids, pair, idx):
    # in new list of ints (ids), replace all consecutive occurences of pair with the new token idx
    newids = []
    i = 0
    while i < len(ids):
        if i < len(ids) - 1 and ids[i] == pair[0] and ids[i+1] == pair[1]:
            newids.append(idx)
            i += 2
        else:
            newids.append(ids[i])
            i += 1
    return newids

tokens2 = merge(tokens, top_pair, 256)

#print(stats)
#print(top_pair)
print(len(tokens))
print(len(tokens2))
#print(merge([5, 6, 6, 7, 9, 1], (6, 7), 99))



# ---- Tokenization ----
ids = list(tokens) # copy so don't destroy original list

vocab_size = 276
num_merges = vocab_size - 256

merges = {}
for i in range(num_merges):
    stats = get_stats(ids)
    pair = max(stats, key=stats.get)
    idx = 256 + i
    print(f"merging {pair} into a new token {idx}")
    ids = merge(ids, pair, idx)
    merges[pair] = idx

print(len(tokens) / len(ids))

vocab = {idx: bytes([idx]) for idx in range(256)}
for (p0, p1), idx in merges.items():
    vocab[idx] = vocab[p0] + vocab[p1]
def decode(ids):
    # give ids (list of integers), return Python string
    tokens = b"".join(vocab[idx] for idx in ids)
    text = tokens.decode("utf-8", errors='replace')
    return text

def encode(text):
    # given a string, return list of integers (the token)
    tokens = list(text.encode("utf-8"))
    while len(tokens) >= 2:
        stats = get_stats(tokens)
        pair = min(stats, key=lambda p: merges.get(p, float("inf")))
        if pair not in merges:
            break
        idx = merges[pair]
        tokens = merge(tokens, pair, idx)
    return tokens

print(decode(encode("HELLO hello world!")))