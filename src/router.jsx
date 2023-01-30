import {createBrowserRouter, Navigate} from "react-router-dom";
import DefaultLayout from "./components/Layout/DefaultLayout";
import GuestLayout from "./components/Layout/GuestLayout";
import Reports from "./views/Reports";
import Login from "./views/Login";
import NotFound from "./views/NotFound";
import Signup from "./views/Signup";
import Habits from "./views/Habits";

const router = createBrowserRouter([
    {
        path: '/',
        element: <DefaultLayout/>,
        children: [
            {
                path: '/',
                element: <Navigate to="/habits" />
            },
            {
                path: '/reports',
                element: <Reports/>
            },
            {
                path: '/habits',
                element: <Habits/>
            },
        ]
    },
    {
        path: '/',
        element: <GuestLayout/>,
        children: [
            {
                path: '/login',
                element: <Login/>
            },
            {
                path: '/signup',
                element: <Signup/>
            },
        ]
    },
    {
        path: '/*',
        element: <NotFound/>
    }
])

export default router;