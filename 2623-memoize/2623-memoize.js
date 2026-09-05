/**
 * @param {Function} fn
 */
function memoize(fn) {
    let cache = new Map();
    return (...args) => {
        const key = JSON.stringify(args);
        return cache.has(key) ? cache.get(key) : cache.set(key, fn(...args)).get(key);
    }
}