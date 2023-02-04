import { useState } from "react";
import { useRef } from "react";
import { Link } from "react-router-dom";
import axiosClient from "../axios-client";
import { useStateContext } from "../contexts/ContextProvider";

export default function Signup(){
    const nameRef = useRef();
    const emailRef = useRef();
    const passwordRef = useRef();
    const passwordConfRef = useRef();

    const [errors,setErrors] = useState(null);
    const {setUser, setToken } = useStateContext();

    const onSubmit = (ev) => {
        ev.preventDefault();

        const payload = {
            name: nameRef.current.value,
            email: emailRef.current.value,
            password: passwordRef.current.value,
            password_confirmation: passwordConfRef.current.value
        }

        axiosClient.post('/signup',payload)
        .then(({data}) => {
            setUser(data.user);
            setToken(data.token);
        })
        .catch(err => {
            const response = err.response;
            if(response && response.status === 422){
                console.log(response.data.errors);
                setErrors(response.data.errors)
            }
        })

        console.log(payload);
    }

    return (
        
        <form onSubmit={onSubmit}>
            <h1 className="title">Signup for free</h1>
            <input ref={nameRef} type="text" placeholder="Full Name" />
            <div className= {`alert-cont ${ errors ? ('name' in errors ? 'active' : '') : ''}`}>
                <div className="alert animated ">{errors && 'name' in errors && errors.name.map((error) => (
                    <p key={error}>{error}</p>
                ))}</div>
            </div>
            <input ref={emailRef} type="email" placeholder="Email" />
            <div className= {`alert-cont ${ errors ? ('email' in errors ? 'active' : '') : ''}`}>
                <div className="alert animated ">{errors && 'email' in errors && errors.email.map((error) => (
                    <p key={error}>{error}</p>
                ))}</div>
            </div>
            <input ref={passwordRef} type="password" placeholder="Password" />
            <div className= {`alert-cont pass ${ errors ? ('password' in errors ? 'active' : '') : ''}`}>
                <div className="alert animated ">{errors && 'password' in errors && errors.password.map((error) => (
                    <p key={error}>{error}</p>
                ))}</div>
            </div>
            <input ref={passwordConfRef} type="password" placeholder="Password Confirmation" />
            <button className="btn btn-block">Signup</button>
            <p className="message">
                Already registered? <Link to="/login">Sign in</Link>
            </p>
        </form>
            
    )
}