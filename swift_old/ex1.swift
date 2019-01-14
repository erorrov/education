var first: Int8
var second: UInt8

first = Int8.min
second = UInt8.max

print(first)
print(second)


var intFirst = 100
var intSecond: Int = 200

var intTmp: Int

intTmp = intFirst
intFirst = intSecond
intSecond = intTmp

print("intFirst = \(intFirst)")
print("intSecond = \(intSecond)")
