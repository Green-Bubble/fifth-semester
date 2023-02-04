import { useRef, useState } from "react";
import { Link } from "react-router-dom";
import axiosClient from "../axios-client";
import { useStateContext } from "../contexts/ContextProvider";

export default function Login(){
    const emailRef = useRef();
    const passwordRef = useRef();

    const [errors,setErrors] = useState(null);
    const {setUser, setToken } = useStateContext();

    const onSubmit = (ev) => {
        ev.preventDefault();

        const payload = {
            email: emailRef.current.value,
            password: passwordRef.current.value,
        }

        axiosClient.post('/login',payload)
        .then(({data}) => {
            setUser(data.user);
            setToken(data.token);
        })
        .catch(err => {

            const response = err.response;
            if(response && response.status === 422){
                if(response.data.errors){
                    setErrors(response.data.errors)
                } else {
                    setErrors({
                        password: [
                            response.data.message
                        ]
                    })
                }
                
            }
        })
    }

    return (
        <form onSubmit={onSubmit}>
            <h1 className="title">Login into your account</h1>
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
            <button className="btn btn-block">Login</button>
            <p className="message">
                Not Registered? <Link to="/signup">Create an account</Link>
            </p>
        </form>
    )
}