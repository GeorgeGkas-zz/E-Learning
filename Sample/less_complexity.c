for (int A = 1; A < N - 2; A++) {
        int ProfitA = Sum(array[0...A-1]);
        int ProfitB = array[A];
        int ProfitC = Sum(array[A+1...N-1])
        for (int B = 1; B < N - 1; B++) {
                //here the values are "current" - valid
 
                //and here they are being prepared for the next iteration
                ProfitB = ProfitB + array[A+B-1];
                ProfitC = ProfitC - array[A+B]);
        }
}
