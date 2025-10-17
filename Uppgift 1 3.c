//
//  main.c
//  DVA117
//
//  Created by Peter Ulfstedt on 5.9.2025.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    float pricewvat, price, vat;
    int percent;
    printf("Price on article (including VAT): ");
    scanf("%f", &pricewvat);
    printf("VAT (percentage as integer): ");
    scanf("%d", &percent);
    price=pricewvat/(1+percent/100.0);// Räknar ut priset utan VAT
    vat=pricewvat-price;//Och själva VAT
    printf("Price excluding VAT is  %.2fSEK\n", price);
    printf("The VAT is %.2fSEK\n\n",vat);
    return 0;
}
