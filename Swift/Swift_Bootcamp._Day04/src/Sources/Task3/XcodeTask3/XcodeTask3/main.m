#import <Foundation/Foundation.h>
#include "CoffeeShop.h"
#import "XcodeTask3-Bridging-Header.h"
//#import <XcodeTask3-Swift.h>
int main(int argc, const char * argv[]) {
    // установка французской локализации
    CoffeeShop *Сappuccino = [[CoffeeShop alloc] initWithName:@"Сappuccino" price:2];
    CoffeeShop *Americano = [[CoffeeShop alloc] initWithName:@"Americano" price:1.5];
    CoffeeShop *Latte = [[CoffeeShop alloc] initWithName:@"Latte" price:2.3];
//    BaristaMachine * Man  [[BaristaMachine alloc] ]
//    BaristaMachine * man
//    Barista
//    Barista

    Barista *ManOne = [[Barista alloc] initWithName:@"SerGay" surname:@"Mort" experience:@"1 Year"];
    printf("%s", "Choose coffee in menu:");
    printf("1. %s %0.2f$", [Сappuccino.name UTF8String], Сappuccino.price);
    printf("2. %s %0.2f$", [Americano.name UTF8String], Americano.price);
    printf("3. %s %0.2f$", [Latte.name UTF8String],  Latte.price);
    int choice =  0;
    NSLog(@"Enter your choice (1-3):");
    while(choice < 1 || choice > 3) {
    scanf("%d", &choice);
    switch (choice) {
        case 1:
//            NSLog(@"You chose %@ %@$", Сappuccino.name, [NSString stringWithFormat:@"%0.2f", Сappuccino.price]);
            [ManOne brew:Сappuccino];
//            ManOne.brew()
            break;
        case 2:
//            NSLog(@"You chose %@ %@$", Americano.name, [NSString stringWithFormat:@"%0.2f", Americano.price]);
            [ManOne brew:Americano];
            break;
        case 3:
//            NSLog(@"You chose %@ %@$", Latte.name, [NSString stringWithFormat:@"%0.2f", Latte.price]);
            [ManOne brew:Latte];
            break;
        default:
            NSLog(@"Invalid choice.");
            break;
    }
        rewind(stdin);
    }
    
   return 0;
}
