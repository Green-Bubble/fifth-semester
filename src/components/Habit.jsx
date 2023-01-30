import React, { useEffect, useState } from 'react'
import Icon from '@mdi/react';
import { mdiClose , mdiMinus, mdiCheck} from '@mdi/js';
import axiosClient from '../axios-client';
import { isSameDay } from 'date-fns';

export default function Habit(props) {
    const [marked,setMarked] = useState(() => {
        const state = props.habit.day_marks[0]?.state;

        if(state === undefined){
            return null;
        } else if(state === 'done'){
            return true;
        } else {
            return false;
        }
    });

    useEffect(() => {
        setMarked(() => {
            const state = props.habit.day_marks.find(day_mark => {
                const date = new Date(day_mark.mark_date);
                return isSameDay(date,props.selectedDate);
            })?.state;

            if(state === undefined){
                return null;
            } else if(state === 'done'){
                return true;
            } else {
                return false;
            }
        });
    },[props.selectedDate])

    const onHabitStateClicked = () => {

        const newState = !marked;
        setMarked(newState);

        const payload = {
            habit_id: props.habit.id,
            mark_date: props.selectedDate,
            state: newState ? 'done' : 'failed',
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
