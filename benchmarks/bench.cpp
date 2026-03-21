#include <benchmark/benchmark.h>
#include "libtokenizer/libtokenizer.hpp"

void register_bench(const std::string& name) {
  benchmark::RegisterBenchmark(
      name,
      [](benchmark::State& state) {
        for (auto _ : state) {
          pytokenizer::core::Tokenizer tokenizer;
          tokenizer.foo();
        }
      });
}

int main(int argc, char** argv) {
  benchmark::Initialize(&argc, argv);
  register_bench("foo");

  benchmark::RunSpecifiedBenchmarks();
  return 0;
}