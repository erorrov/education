let ci:Int, cf: Float, cd: Double
ci = 18; cf = 16.4; cd = 5.7

var sumFloat: Float = Float(ci) + cf + Float(cd)
var sumInt: Int = Int(Float(ci) * cf * Float(cd))
var divDouble: Double = Double(cf).truncatingRemainder(dividingBy: cd) //what?

print("+", sumFloat, "\n*", sumInt, "\n%", divDouble)
