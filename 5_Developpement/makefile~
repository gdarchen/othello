SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99  -I$(INCLUDEDIR)  
LDFLAGS=-lm -lcurses
EXEC=faireUnePartie
TEST1=TestListeCoupsPossibles
TEST2=TestTADs


all :  $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(SRCDIR)/FaireUnePartie.o $(SRCDIR)/ListesCoupsPossibles.o  $(SRCDIR)/TAD_Couleur.o  $(SRCDIR)/TAD_Coup.o  $(SRCDIR)/TAD_Coups.o  $(SRCDIR)/TAD_Pion.o  $(SRCDIR)/TAD_Plateau.o  $(SRCDIR)/TAD_Position.o $(SRCDIR)/Affichage.o
	$(CC)  -o $@ $^ $(LDFLAGS) 

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< 

tests:  $(TESTDIR)/$(TEST1) $(TESTDIR)/$(TEST2)
	
$(TESTDIR)/$(TEST1):$(SRCDIR)/TestListeCoupsPossibles.o $(SRCDIR)/ListesCoupsPossibles.o $(SRCDIR)/FaireUnePartie.o $(SRCDIR)/TAD_Couleur.o  $(SRCDIR)/TAD_Coup.o  $(SRCDIR)/TAD_Coups.o  $(SRCDIR)/TAD_Pion.o  $(SRCDIR)/TAD_Plateau.o  $(SRCDIR)/TAD_Position.o  
	$(CC) -o $(TESTDIR)/$(TEST1)/TestListeCoupsPossibles $(SRCDIR)/TestListeCoupsPossibles.o $(SRCDIR)/ListesCoupsPossibles.o $(SRCDIR)/FaireUnePartie.o $(SRCDIR)/TAD_Couleur.o  $(SRCDIR)/TAD_Coup.o  $(SRCDIR)/TAD_Coups.o  $(SRCDIR)/TAD_Pion.o  $(SRCDIR)/TAD_Plateau.o  $(SRCDIR)/TAD_Position.o  $(LDFLAGS) -lcunit

$(TESTDIR)/$(TEST2):$(SRCDIR)/TestTADs.o $(SRCDIR)/ListesCoupsPossibles.o $(SRCDIR)/FaireUnePartie.o $(SRCDIR)/TAD_Couleur.o  $(SRCDIR)/TAD_Coup.o  $(SRCDIR)/TAD_Coups.o  $(SRCDIR)/TAD_Pion.o  $(SRCDIR)/TAD_Plateau.o  $(SRCDIR)/TAD_Position.o  
	$(CC) -o $(TESTDIR)/$(TEST2)/TestTADs $(SRCDIR)/TestTADs.o  $(SRCDIR)/ListesCoupsPossibles.o $(SRCDIR)/FaireUnePartie.o $(SRCDIR)/TAD_Couleur.o  $(SRCDIR)/TAD_Coup.o  $(SRCDIR)/TAD_Coups.o  $(SRCDIR)/TAD_Pion.o  $(SRCDIR)/TAD_Plateau.o  $(SRCDIR)/TAD_Position.o  $(LDFLAGS) -lcunit

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/$(TEST1)/*
	rm -rf $(TESTDIR)/$(TEST2)/*

	
	
