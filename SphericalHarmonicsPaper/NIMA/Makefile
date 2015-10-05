
# LaTeX Compiler Command
TEX = pdflatex
# BibTeX Compiler Command
BIBTEX = bibtex

# LaTeX Head File name
NAME = spherical_paper

# PDF name
PDFNAME = NuDot_SphericalHarmonics

# SVN Versioning
#SVN_REVISION = $(shell svn info | grep Revision | awk '{print $$2}')
SVN_REVISION := $(git desribe --always)
SVN_FILE = paper_versioning.tex

# List of editable tex files
TEXFILES := $(filter-out $(SVN_FILE),$(wildcard *.tex))
# List of editable bib files
BIBFILES := $(filter-out $(NAME)Notes.bib,$(wildcard *.bib))



.PHONY: count clean svn figs aps els

# Make the PDF. First check to see if any of the latex files have changed
$(NAME).pdf: $(NAME).aux $(NAME).bbl
#	This loops over the latex until all references have been sorted
	@while (echo RUN Latex in loop;				\
		$(TEX) $(NAME).tex ; 				\
		grep -q "Rerun to get" $(NAME).log)	\
	do true;						\
	done
	@mv $(NAME).pdf $(PDFNAME).pdf

# Compile the aux files. Check if any of the tex files have changed.
$(NAME).aux: $(TEXFILES) 
	@echo FILES: $(TEXFILES) $(BIBFILES)
	@echo RUN latex $(NAME).tex in aux
	@$(TEX) $(NAME).tex

# Compile bibtex files. Check if any of the bib files have changed.
$(NAME).bbl $(NAME).blg: $(NAME).aux $(BIBFILES)
	@echo RUN bibtex from specific
	@echo $(NAME)
	@$(BIBTEX) $(NAME)

# Compile tex file
%.tex:
	@echo RUN Latex $(NAME) from base
	@$(TEX) $(NAME).tex

# Create the SVN file
svn:
	@echo "\\\\newcommand{\\PaperRevision}{$(SVN_REVISION)}" > $(SVN_FILE)

# Word counts
count:
	@texcount -nobib -inc -total $(NAME).tex

# Clean everything up
clean:
	rm -f *.aux *.log *.bbl *.blg paper_versioning.tex *.spl *~ images/*~ \
	*.toc 

# Just force the compile command
make:
	@echo "\\\\newcommand{\\PaperRevision}{$(SVN_REVISION)}" > $(SVN_FILE)
	@$(TEX) $(NAME)
	@$(BIBTEX) $(NAME)
	@$(TEX) $(NAME)
	@$(TEX) $(NAME)

aps:
	@echo "Linking APS files."
	@ln -sf preamble_aps.tex preamble.tex
	@ln -sf authors_aps_20150403.tex authors.tex

els:
	@echo "Linking Elsevier files."
	@ln -sf preamble_els.tex preamble.tex
	@ln -sf authors_els_20150526.tex authors.tex

figs:
	@make -C images/
