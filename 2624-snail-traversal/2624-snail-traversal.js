/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    const nums=this;
    if (rowsCount * colsCount !== nums.length) return [];

    arr=Array.from({length:rowsCount},()=>[])

    for(let i=0; i<nums.length;i++){
        ind=i%(rowsCount*2)<rowsCount
        ind = ind ? i%(rowsCount) : rowsCount - 1 - (i%(rowsCount))
        arr[ind].push(nums[i])
    }
    return arr
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */