# Progetto-Tetris

## Descrizione
Il progetto è una replica fedele del gioco originale di Tetris utilizzando la stampa direttamente sul terminale.
Per il gioco sono state utilizzate il minor numero di librerie possibili e, in particolare, abbiamo cercato di utilizzare il più possibile le librerie integrate in ncurses.

## Installazione
Per installare tutti i file del gioco è sufficiente scaricare dalla repository GitHub tramite:

- $ git clone https://github.com/tankest2015/Progetto-Tetris.git

- oppure accedendo direttamente tramite browser al link >> https://github.com/tankest2015/Progetto-Tetris

1. Compilare il gioco tramite shell Linux
Per compilare il gioco in una qualsiasi distribuzione di Linux è sufficiente utilizzare il comando 'make' per compilare, tramite g++, i file .o e l'eseguibile.

2. Compilare il gioco tramite shell Windows
È necessario installare un ambiente Unix come MinGW, MSYS2 oppure Cygwin ed installarci il comando 'make'.
Successivamente tramite il comando 'make' sarà possibile compilare i file .o e l'eseguibile.

Per entrambi i sistemi operativi è possibile controllare se il compilatore g++ è installato eseguendo il comando 'g++ --version'.
Ulteriormente, è necessaria l'installazione della libreria grafica ncurses che è possibile ottenere tramite il comando '$ sudo apt-get install libncurses5-dev libncursesw5-dev' su Linux, oppure installando le seguenti librerire per Windows: 'pdcurses', 'libncurses', 'libpdcurses', 'ncurses'.

## Utilizzo
Per avviare il gioco bisogna avviare l'eseguibile con il comando './main'.
Il gioco presente quattro diverse sezioni nel menu principale: "Play", "Leaderboard", "Options", "Exit";

- Play --
Fa iniziare una nuova partita al giocatore.
Il gioco è inizialmente settato a difficoltà "Easy" e aumentando il punteggio si raggiungono le successive difficoltà: "Medium", "Hard" e "Extreme".
I comandi del gioco sono i seguenti:

    Freccia Sinistra: Muove il tetramino a sinistra;

    Freccia Destra: Muove il tetramino a destra;

    Freccia Basso: Muove il tetramino in basso;

    Tasto A: Ruota il tetramino a sinistra;

    Tasto D: Ruota il tetramino a destra;

    Barra Spaziatrice: Sposta il tetramino direttamente sulla posizione sottostante;

    Tasto Esc: Interrompe il gioco e apre il menu di pausa;


- Leaderboard --
Permette di visualizzare la classifica dei giocatori mostrando i campi: "Position", "Name", "Time", "Points", "Completed rows".
La Leaderboard viene creata automaticamente dal programma dopo la prima esecuzione del gioco e si aggiorna costantemente con le nuove partite effettuate, ordinate in base al punteggio.
La linea evidenziata, nella schermata della Leaderboard, permette di visualizzare velocemente l'ultimo giocatore inserito.


- Options --
Mostra una schermata al giocatore che permette di cambiare la grafica dei tetramini.
Il giocatore può scegliere se giocare con la grafica classica (impostata di Default) o utilizzare la grafica Neon.


- Exit --
Permette di uscire correttamente dal programma.

## Tecnologie Usate
Il gioco è scritto interamente in C++ e si avvale di librerie standard del linguaggio e di quella grafica ncurses.

## Riconoscimenti
Ringraziamo il creatore del canale "Casual Coder" per la produzione della playlist tutorial su come utilizzare ncurses.
Link alla playlist del tutorial di ncurses >> https://www.youtube.com/playlist?list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v
