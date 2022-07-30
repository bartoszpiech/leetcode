package main

import "fmt"

func containsDuplicate(nums []int) bool {
    var numCount = make(map[int]int)
    for _, v := range nums {
        if numCount[v]++;  numCount[v] > 1 {
            return true
        }
    }
    return false
}

func main() {
    fmt.Println(containsDuplicate([]int{1,2,3,4}))
}
