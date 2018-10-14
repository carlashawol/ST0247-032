public class Punto1_1 { 
   private String str1;
   private String str2;
   private int distancia;
   private int[][] matriz;

   public void setWords(String str1, String str2) {
      this.str1 = str1.toLowerCase();
      this.str2 = str2.toLowerCase();
      calculoLevenshtein();
   }

   public int getDistancia() {
      return distancia;
   }

   private void calculoLevenshtein() {
      matriz = new int[str1.length() + 1][str2.length() + 1];
      for (int i = 0; i <= str1.length(); i++) {
         matriz[i][0] = i;
      }
      for (int j = 0; j <= str2.length(); j++) {
         matriz[0][j] = j;
      }
      for (int i = 1; i < matriz.length; i++) {
         for (int j = 1; j < matriz[i].length; j++) {
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
               matriz[i][j] = matriz[i - 1][j - 1];
            } else {
               int min = Integer.MAX_VALUE;
               if ((matriz[i - 1][j]) + 1 < min) {
                  min = (matriz[i - 1][j]) + 1;
               }
               if ((matriz[i][j - 1]) + 1 < min) {
                  min = (matriz[i][j - 1]) + 1;
               }
               if ((matriz[i - 1][j - 1]) + 1 < min) {
                  min = (matriz[i - 1][j - 1]) + 1;
               }
               matriz[i][j] = min;
            }
         }
      }
      distancia = matriz[str1.length()][str2.length()];
   }

    public static void main(String[] args) {
      String str1 = "identificar";
      String str2 = "identidad";

      Punto1_1 P1 = new Punto1_1();
      P1.setWords(str1, str2);

      System.out.println("Palabra1: " + str1);
      System.out.println("Palabra2: " + str2);
      System.out.println("\nDistancia de Levenshtein:\n" + P1.getDistancia());
   }
}
