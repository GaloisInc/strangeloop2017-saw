PDFS=strangeloop-saw.pdf
TEXS=strangeloop-saw.tex

PANDOC_OPTS=-s -t beamer --latex-engine=xelatex \
            -V theme:Galois -V section-titles:false # --listings
all: ${PDFS}

tex: ${TEXS}

%.pdf: %.md
	pandoc -H header.tex ${PANDOC_OPTS} -o $@ $<

%.tex: %.md
	pandoc -H header.tex ${PANDOC_OPTS} -o $@ $<

clean:
	rm -f ${PDFS} ${TEXS}
