import React, { useEffect, useState } from 'react'
import Icon from '@mdi/react';
import { mdiClose , mdiMinus, mdiCheck} from '@mdi/js';
import axiosClient from '../axios-client';

export default function Habit(props) {
    const [marked,setMarked] = useState(null);

    function onHabitStateClicked(){
        setMarked(!marked);

        const payload = {
            habit_id: props.habit.id,
            mark_date: new Date(),
            state: marked ? 'done' : 'failed',
            value: null
        }

        axiosClient.post('/daymark/store',payload)
        .then((response)=>{
            console.log("STORE DAY MARK",response);
        })
        .catch((error) => {

            console.log(error.response.data.errors);
        })
    }

    return (
    <div className='habit'>
        <span 
        style={{color: props.habit.color}}
        onClick={() => {props.onHabitClick(props.habit)}}>
            {props.habit.title}
        </span>
        <span 
            className='habit-state'
            onClick={() => {onHabitStateClicked()}}
        >
            {marked === null && 
                <Icon path={mdiMinus} size={1} />
            }
            {marked === true &&
                <Icon path={mdiCheck} size={1} />
            }
            {marked === false &&
                <Icon path={mdiClose} size={1} />
            }
        </span>
    </div>
    )
}
