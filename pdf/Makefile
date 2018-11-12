TEX = pdfcsplain
PDFFILES = plaintex.pdf

all: $(PDFFILES)

%.pdf: %.tex
	$(TEX) $<
	$(TEX) $<

.PHONY: clean

clean:
	rm *.log *.ref
