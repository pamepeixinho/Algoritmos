O algoritmo LCS encontra a maior subsequência comum entre duas strings,
sendo uma subsequência um conjunto de caracteres que aparecem em uma ordem
de esquerda para direita, sendo estes caracteres não necessariamente 
consecutivos.

int lcs( string X, string Y, int sizeX, int sizeY)
{
   int L[sizeX+1][sizeY];
   for (int i=0; i<=sizeX; i++)
   {
     for (int j=0; j<=sizeY; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   int index = L[sizeX][sizeY];
   return index;
    // Following code is used to print LCS
   /*char lcs[index+1];
   lcs[index] = '\0';
 
   int i = sizeX, j = sizeY;
   while (i > 0 && j > 0)
   {
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1];
          i--; j--; index--;
      }

      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
   return string(lcs);*/
}