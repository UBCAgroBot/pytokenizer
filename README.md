## LLM Pretraining: Tokenizer

**Details:** this project focuses on the foundational infrastructure of LLM pretraining, specifically the creation of a highly optimized tokenizer. The team will build a tokenizer from scratch that mimics the functionality of `tiktoken` (encoding, decoding, tokenize), prioritizing fast latency. The core implementation will be written in C++ and then ported over to Python.

**Team Size:** 2-3

**Progression**

1. locate a deduplicated dataset suitable for pretraining.  
2. develop a Byte Pair Encoding tokenizer in C++ that stores merges and provides fast mapping from new tokens to original tokens. Should store and write merges in a format similar to the tokenizer format examples in the reference section (tokenizer.json)  
3. validate correctness using Google Test and profile latency using Google Benchmark. (because BPE is deterministic, it should perform the same set of merges as the `tiktoken` library)  
4. implement linked list data structures to asymptotically speed up the tokenization process (Reference: [Fast MinBPE](https://yanivle.github.io/ai/2024/02/23/fast_minbpe.html)).  
5. Implement batching to process data streams without loading the entire dataset into memory.  
6. create bindings using `pybind11` to export the module to Python.  
7. if there is time we can also try to implement SentencePiece, or try to optimize for benchmark latency

**Technologies**

* **Languages:** C++, Python, CMake  
* **Libraries & Frameworks:** Google Benchmark, Google Test, Pybind11  
* **References:**   
  * Original BPE implementation video: [Let's build the GPT Tokenizer](https://www.youtube.com/watch?v=zduSFxRajkE)  
  * Tokenizer format: [DeepSeek-R1 Example](https://huggingface.co/deepseek-ai/DeepSeek-R1/raw/main/tokenizer.json) 
