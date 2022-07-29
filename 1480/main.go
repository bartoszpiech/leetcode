package main

import "fmt"

func runningSum(nums []int) []int {
    var result []int
    for i, _ := range nums {
        var sum int = 0
        for j := 0; j <= i; j++ {
            sum += nums[j]
        }
        result = append(result, sum)
    }
    return result
}

func main() {
    var nums = []int{1, 2, 3, 4}
    fmt.Println(runningSum(nums))
}
