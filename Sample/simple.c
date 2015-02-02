
{
 int Min = 0;
 //assumme that we know the Profits(A,B,C) values! 
 Min = (ProfitA > ProfitB) ? ProfitA : ProfitB;
 Min = (ProfitC > Min) ? ProfitC : Min;
}
