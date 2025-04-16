const express = require('express')
const app = express();
const cors = require('cors')
const port = 8080
const mysql = require('mysql2');

// const rounter = express.Router();


const connection = new mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: 'root', 
  database: 'demo_fullstack'
})


const connectDB=async()=>{connection.connect((err)=>{
        if(err){
            console.log(err);
        }else{
            console.log("connected to db")
            return connection;
        }
    });
}

module.exports ={connectDB};


app.use(cors())
app.use(express.json());


app.post('/login',(req,res)=>{
    const { userName, pass } = req.body;
    const id= userName;
    console.log(id,pass)

    try{
        const query1 ='SELECT * FROM user_password WHERE username = ?';
        connection.query(query1,[id],(err,rows)=>{
            if(err){
                console.error(err);
                res.status(500).send("Failed to check data 1");
                return;
            }

            if(rows.length>0){
                const query2 = 'SELECT * FROM user_password WHERE username =?';
                connection.query(query2,[id],(err,rows)=>{
                    if(err){
                        console.error(err);
                        res.status(500).send("failed to fetch data 2");
                        return;
                    }

                    // console.log(rows[0].password);
                    const saved_password = rows[0].password
                    if(pass===saved_password){

                        res.send("sucessfull");
                        console.log(`login sucessfull for ${id}`);
                    }else{
                        res.send("failed");
                        console.log(`login failed for ${id}, wrong password`);
                    }
                })
            }else{
                console.log("user not registered");
            }
        })
    }catch(err){
        console.error(err);
    }
   
})

app.post('/signUp', (req, res) => {
    const { userName, pass } = req.body;
    const id= userName;
    console.log(id,pass)

    try {
        // Check if user already exists
        const query1 = 'SELECT * FROM user_password WHERE username = ?';
        connection.query(query1, [id], (err, rows) => {
            if (err) {
                console.error(err);
                res.status(500).send("Failed to check data");
                return;
            }

            if (rows.length > 0) {
                // User already exists
                res.status(409).send("User already registered");
            } else {
                // Insert new user
                const query2 = 'INSERT INTO user_password (username, password) VALUES (?, ?)';
                connection.query(query2, [id, pass], (err) => {
                    if (err) {
                        console.error(err);
                        res.status(500).send("Failed to register user");
                        return;
                    }
                    console.log(`${id} added successfully`);
                    res.status(201).json({ message: `${id} added successfully` });

                });
            }
        });
    } catch (e) {
        console.error(e);
        res.status(500).send("Failed to add data");
    }
});

// app.post('/signup',(req,res)=>{
//     console.log(req.body);
//     res.end("hi")
// })

app.get('/getData',async(req,res)=>{
    const query = "select * from user_password";
    const result = connection.query(query,(err, rows, fields) => {
        if (err){ throw err}
        res.json(rows); 
      });
})

app.listen(port,async()=>{
    await connectDB();

    console.log(`server started at port: ${port}`)
})

