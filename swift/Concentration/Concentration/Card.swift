//
//  Card.swift
//  Concentration
//
//  Created by Егор Егоров on 14/01/2019.
//  Copyright © 2019 Егор Егоров. All rights reserved.
//

import Foundation

struct Card {
    var isFaceUp = false
    var isMatched = false
    var seenTimes = 0
    var identifier: Int
    
    static var identifierFactory = 0
    
    static func getUniqueIdentifier() -> Int {
        identifierFactory += 1
        return identifierFactory
    }
    
    init() {
        self.identifier = Card.getUniqueIdentifier()
    }
}
