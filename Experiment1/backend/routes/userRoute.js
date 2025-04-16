const express = require('express');

const router = express.Router();

router.get('/allUser',(req,res)=>{
    res.send('this will fetch all users')
});
router.post('/login',(res,req)=>{
    res.send('this will use for login')
})


module.exports = router;

