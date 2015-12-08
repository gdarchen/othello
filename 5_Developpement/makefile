SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99  -I$(INCLUDEDIR)  
LDFLAGS=-lm -Lcurses 
EXEC=faireUnePartie

all :  $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(SRCDIR)/FaireUnePartie.o
	$(CC)  -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

tests: $(SRCDIR)/TestListeCoupsPossibles.c $(SRCDIR)/TestTADs.c  $(SRCDIR)/ListesCoupsPossibles.c  $(SRCDIR)/TAD_Couleur.c  $(SRCDIR)/TAD_Coup.c  $(SRCDIR)/TAD_Coups.c  $(SRCDIR)/TAD_Pion.c  $(SRCDIR)/TAD_Plateau.c  $(SRCDIR)/TAD_Position.c
	gcc -o $(TESTDIR)/TestListeCoupsPossibles $(TESTDIR)/TestTADs  $(SRCDIR)/TestListeCoupsPossibles.o $(SRCDIR)/TestTADs.o  $(SRCDIR)/ListesCoupsPossibles.o  $(SRCDIR)/TAD_Couleur.o  $(SRCDIR)/TAD_Coup.o  $(SRCDIR)/TAD_Coups.o  $(SRCDIR)/TAD_Pion.o  $(SRCDIR)/TAD_Plateau.o  $(SRCDIR)/TAD_Position.o  $(LDFLAGS) -lcunit


clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*
