/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    // will wait for millis milliseconds
    const P = await new Promise((resolve,reject)=>{
        setTimeout(()=>resolve(millis),millis);
    }); 
    return P;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */