import React, { useEffect } from 'react'
import { Navigate, Outlet } from 'react-router-dom'
import { useStateContext } from '../contexts/ContextProvider'
import { Link } from 'react-router-dom'
import axiosClient from '../axios-client'

export default function DefaultLayout() {
    const {user, token, setUser, setToken} = useStateContext()

    if(!token){
        return <Navigate to="/login"/>
    }

    const onLogout = (ev) => {
        ev.preventDefault();

        axiosClient.post('/logout')
        .then(() => {
            setUser({});
            setToken(null);
        });
    }

    useEffect(() => {
        axiosClient.get('/user')
            .then(({data}) => {
                setUser(data);
            })
    }, []);

    return (
    <div id='defaultLayout'>
        <header>
            <h1 id='logo'>Habit Forge</h1>
            <div>
                {user.name}
                <a href="#" onClick={onLogout} className='btn-logout' >Logout</a>
            </div>
        </header>
        <aside>
            <Link to="/habits">Habits</Link>
            <Link to="/reports">Reports</Link>
        </aside>
        <div className='content'>
            <main>
                <Outlet/>
            </main>
        </div>     
    </div>
    )
}
