//
//  CoffeeShop.m
//  
//
//  Created by Gulian Boris on 3/18/23.
//

#import "CoffeeShop.h"

@implementation CoffeeShop
- (instancetype)initWithName:(NSString *)name price:(CGFloat)price {
    self = [super init];
    if (self) {
        self.name = name;
        self.price = price;
    }
    return self;

}
@end
@implementation Barista

- (instancetype)initWithName:(NSString *)name surname:(NSString *)surname experience:(NSString *)experience {
    self = [super init];
    if (self) {
        self.Name = name;
        self.Surname = surname;
        self.Experience = experience;
    }
    return self;
}
- (id)brew:(CoffeeShop *)coffee {
    printf("Processing brewing coffee...\n");
    printf("Your %s is ready!\n", [coffee.name UTF8String]);
    return self;
}
@end
