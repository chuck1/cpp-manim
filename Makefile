
dot_files = $(shell find build/dot -name "*.dot")
pdf_files = $(patsubst build/dot/%.dot,build/dot/pdf/%.pdf,$(dot_files))
png_files = $(patsubst build/dot/%.dot,build/dot/png/%.png,$(dot_files))

all:
	pbs make config.py

build/dot/pdf/%.pdf: build/dot/%.dot
	@mkdir -p $(dir $@)
	@bash build_dot.bash $< '-Tpdf -o$@ $^'

build/dot/png/%.png: build/dot/%.dot
	@mkdir -p $(dir $@)
	@bash build_dot.bash $< '-Tpng -o$@ $^'

dot: $(pdf_files)

png: $(png_files)

dotclean:
	rm -rf build/dot/*

.PHONY: doc
doc:
	pbs make config.py doc

clean:
	rm -rf build/object/*
	rm -rf build/process/*

testclean:
	rm -rf tests/test_solve_for/build/* -rf

