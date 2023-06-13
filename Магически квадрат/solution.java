import java.util.Scanner;

public class Main {

    public static void createMagicSquare(int n) {
        int[][] magicSquare = new int[n][n]; //inicializiram magi4eskiq kvadrat da sudurja 0 vuv vsqka kletka

        int currentRow = 0;
        int currentColumn = n/2;

        int previousRow = currentRow;
        int previousColumn = currentColumn;

        magicSquare[0][n/2]=1; //postavqm chisloto 1 v sredata na purviq red
        int filledCells = 1; //broj zapulneni kletki


        while (filledCells < n * n)
        {
            if(currentRow==0){currentRow=n-1;} //Ako elementut popada izvun kvadrat4etata v gornata mu 4ast (ako indeksa na reda e nula), to 4isloto se postavq v posledniq red bez da se promenq nomera na stulba
            else {currentRow=currentRow-1;}

            if(currentColumn==0){currentColumn=n-1;}//Ako elementut popada izvun matricata vlqvo (indeksa na stulba e nula), to 4isloto se postavq v nai-desniq stulb bez da se promenq nomera na reda
            else {currentColumn=currentColumn-1;}

            if (magicSquare[currentRow][currentColumn] == 0)
            {
                magicSquare[currentRow][currentColumn] = ++filledCells;
                previousRow = currentRow;
                previousColumn = currentColumn;
            }
            else //Ako elementut e ve4e zaet, 4isloto se postavqq pod elementa, kojto e razpolojen posleden
            {
                currentRow = (previousRow + 1) % n;
                currentColumn = (previousColumn) % n;
                magicSquare[currentRow][currentColumn] = ++filledCells;

                previousRow = currentRow;
                previousColumn = currentColumn;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                System.out.print(magicSquare[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();//broj testove
        int N;//golemina na matrica
        while(t!=0)
        {
          N =scan.nextInt();
          createMagicSquare(N);
          t=t-1;
        }
    }
}