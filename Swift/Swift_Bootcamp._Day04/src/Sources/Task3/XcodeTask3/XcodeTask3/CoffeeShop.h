//
//  CoffeeShop.h
//  XcodeTask2
//
//  Created by Gulian Boris on 3/18/23.
//

#import <Foundation/Foundation.h>
#import "XcodeTask3-Bridging-Header.h"
//#import <>
NS_ASSUME_NONNULL_BEGIN

@interface CoffeeShop : NSObject
- (instancetype)initWithName:(NSString *)name price:(CGFloat)price;
@property NSString *name;
@property double price;
@end


@interface Barista : NSObject

@property NSString *Name;
@property NSString *Surname;
@property NSString *Experience;

- (instancetype)initWithName:(NSString *)name surname:(NSString *)surname experience:(NSString *)experience;
- (id)brew:(CoffeeShop *)coffee;

@end

NS_ASSUME_NONNULL_END

