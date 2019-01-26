//
//  ViewController.swift
//  Concentration
//
//  Created by Егор Егоров on 13/01/2019.
//  Copyright © 2019 Егор Егоров. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    lazy var game = Concentration(numberOfPairsOfCards: (cardButtons.count + 1) / 2)
    @IBOutlet var cardButtons: [UIButton]!
    @IBOutlet weak var flipCountLabel: UILabel!
    @IBOutlet weak var scoreLabel: UILabel!
    @IBOutlet weak var newGameButton: UIButton!
    var emojiChoices = [String]()
    var emoji = [Int:String]()
    var themes = [String:[String]]()
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        themes["things"]    = ["💻", "📱", "⌚️", "⌨️", "🖥", "📺", "🖨", "📷", "💾"]
        themes["animals"]   = ["🐶", "🐹", "🐵", "🐼", "🐧", "🐔", "🐸", "🐤", "🐷"]
        themes["sport"]     = ["⚽️", "🏀", "🏈", "⚾️", "🥎", "🎾", "🏐", "🏉", "🎱"]
        themes["faces"]     = ["😍", "😜", "😎", "😳", "😂", "😏", "😡", "😴", "😱"]
        themes["food"]      = ["🍏", "🍎", "🍔", "🍕", "🍩", "🧀", "🍆", "🍓", "🥐"]
        themes["flags"]     = ["🇯🇵", "🇺🇸", "🇷🇺", "🇰🇿", "🇺🇦", "🇧🇾", "🇦🇿", "🇩🇪", "🇨🇦"]
        
        startNewGame()
    }
    
    @IBAction func startNewGame() {
        emojiChoices = themes[Array(themes.keys).randomElement()!]! //looks bad
        emoji = [Int:String]()
        game = Concentration(numberOfPairsOfCards: (cardButtons.count + 1) / 2)
        newGameButton.isHidden = true
        updateViewFromModel()
    }
    
    @IBAction func touchCard(_ sender: UIButton) {
        if let cardNumber = cardButtons.index(of: sender) {
            
            if let lastCardIndex = game.indexOfOneAndOnlyFaceUpCard, !game.cards[cardNumber].isFaceUp, !game.cards[cardNumber].isMatched {
                if game.cards[lastCardIndex].identifier == game.cards[cardNumber].identifier {
                    game.score += 2
                } else {
                    if game.cards[lastCardIndex].seenTimes > 1 { game.score -= 1 }
                    if game.cards[cardNumber].seenTimes > 1 { game.score -= 1 }
                }
            }
            
            game.chooseCard(at: cardNumber)
            updateViewFromModel()
        } else {
            print("choosen card was not in cardButtons")
        }
    }
    
    func updateViewFromModel() {
        for index in cardButtons.indices {
            let button = cardButtons[index]
            let card = game.cards[index]
            if card.isFaceUp {
                button.setTitle(emoji(for: card), for: UIControl.State.normal)
                button.backgroundColor = #colorLiteral(red: 1, green: 1, blue: 1, alpha: 1)
            } else {
                button.setTitle("", for: UIControl.State.normal)
                button.backgroundColor = card.isMatched ? #colorLiteral(red: 1, green: 0.5763723254, blue: 0, alpha: 0) : #colorLiteral(red: 1, green: 0.5763723254, blue: 0, alpha: 1)
            }
        }
        
        if game.cards.allSatisfy({$0.isMatched}) {
            newGameButton.isHidden = false
        }
        
        scoreLabel.text = "Score: \(game.score)"
        flipCountLabel.text = "Flips: \(game.flipCount)"
    }
    
    func emoji(for card: Card) -> String {
        if emoji[card.identifier] == nil, emojiChoices.count > 0 {
            let randomIndex = Int(arc4random_uniform(UInt32(emojiChoices.count)))
            emoji[card.identifier] = emojiChoices.remove(at: randomIndex)
        }
        return emoji[card.identifier] ?? "?"
    }
}
