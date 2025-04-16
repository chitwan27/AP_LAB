import React from "react";
import "./App.css";
import { useState,useEffect } from "react";

function App() {
  const [userName, setUserName] = useState("");
  const [pass, setPass] = useState("");
  const [isLogin,setIsLogin] =useState("false");
  const [loginText,setLoginText] = useState("Login");

  useEffect(()=>{
    isLogin?setLoginText("Login"):setLoginText("Sign up");
  })

  const handleLogin=()=>{
    try{
      setIsLogin(!isLogin);
    }catch(e){
      alert(e);
    }
  }

  const handleSubmit=async()=>{
    try {
      const endpoint = isLogin ? '/login' : '/signUp';
      const response = await fetch(`http://localhost:8080${endpoint}`, {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({ userName, pass }),
      });
  
      if (!response.ok) {
        throw new Error(`Error: ${response.status} - ${response.statusText}`);
      }
  
      // const data = await response;
      console.log('Success:', await response);
    } catch (error) {
      console.error('Authentication failed:', error.message);
    }
  }
  return (
    <>
      <div className="wrapper">
        <div className="card">

          <h1 onClick={handleLogin}>{loginText}</h1>
          <label htmlFor="username">User Name</label>

          <input
            type="text"
            placeholder="Username"
            id="username"
            onChange={(e) => {
              setUserName(e.target.value);
            }}
          />
          <label htmlFor="password">Password</label>

          <input
            type="password"
            placeholder="Password"
            id="password"
            onChange={(e) => {
              setPass(e.target.value);
            }}
          />

          <button id="submit" onClick={handleSubmit}>Submit</button>
        </div>
      </div>
    </>
  );
}

export default App;
