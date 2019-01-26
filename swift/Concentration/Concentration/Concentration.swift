//
//  Concentration.swift
//  Concentration
//
//  Created by Егор Егоров on 14/01/2019.
//  Copyright © 2019 Егор Егоров. All rights reserved.
//

import Foundation

class Concentration {
    var cards = [Card]()
    var indexOfOneAndOnlyFaceUpCard: Int?
    var flipCount: Int
    var score: Int
    
    func chooseCard(at index: Int) {
        if !cards[index].isMatched {
            if !cards[index].isFaceUp {
                flipCount += 1
                cards[index].seenTimes += 1
            }
            
            if let matchIndex = indexOfOneAndOnlyFaceUpCard, matchIndex != index {
                if cards[matchIndex].identifier == cards[index].identifier {
                    cards[matchIndex].isMatched = true
                    cards[index].isMatched = true
                }
                cards[index].isFaceUp = true
                indexOfOneAndOnlyFaceUpCard = nil
            } else {
                for flipdownIndex in cards.indices {
                    cards[flipdownIndex].isFaceUp = false
                }
                cards[index].isFaceUp = true
                indexOfOneAndOnlyFaceUpCard = index
            }
        }
        
        //print(cards[index])
    }
    
    
    init(numberOfPairsOfCards: Int) {
        flipCount = 0
        score = 0
        
        for _ in 1...numberOfPairsOfCards {
            let card = Card()
            cards += [card, card]
        }
        cards.shuffle()
    }
}
