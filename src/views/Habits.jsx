import { useEffect } from "react";
import axiosClient from "../axios-client";
import CreateHabit from "./CreateHabit";

export default function Habits(){

    useEffect(() => {
        axiosClient.post('/habits')
        .then((response)=>{
            console.log(response);
        })
        .catch((error) => {

            console.log(error.response.data.errors); 
        })
    });

    return (
        <>
            <div>
                Habits
            </div>
            <CreateHabit/>
        </>
    )
}