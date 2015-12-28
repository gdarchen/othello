TEX = pdflatex -shell-escape -interaction=nonstopmode -file-line-error
MOVE = mv
FICHIERSCOMP = FichiersDeCompilation-LaTeX
OUVRIRPDF = xdg-open

all : Rapport.pdf

view :
	$(OUVRIRPDF) Rapport.pdf

Rapport.pdf Rapport.tex Rapport.aux Rapport.out Rapport.toc Rapport.log :
	$(TEX) Rapport.tex
	$(MOVE) Rapport.aux ./$(FICHIERSCOMP)
	$(MOVE) Rapport.out ./$(FICHIERSCOMP)
	$(MOVE) Rapport.toc ./$(FICHIERSCOMP)
	$(MOVE) Rapport.log ./$(FICHIERSCOMP)

clean :
	rm -rf ./$(FICHIERSCOMP)/*.aux
	rm -rf ./$(FICHIERSCOMP)/*.log
	rm -rf ./*.pdf
	rm -rf ./$(FICHIERSCOMP)/*.out
	rm -rf ./$(FICHIERSCOMP)/*.toc
