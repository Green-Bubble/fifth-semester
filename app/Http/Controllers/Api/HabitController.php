<?php

namespace App\Http\Controllers\Api;

use App\Http\Controllers\Controller;
use App\Models\Habit;
use App\Http\Requests\StoreHabitRequest;
use App\Http\Requests\UpdateHabitRequest;
use Illuminate\Validation\Rule;

class HabitController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        //return 
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \App\Http\Requests\StoreHabitRequest  $request
     * @return \Illuminate\Http\Response
     */
    public function store(StoreHabitRequest $request)
    {
        $validated = $request->validate([
            'type' => [
                'required',
                Rule::in(['positiveYN'])
            ],
            'color' => 'required|regex:/^#[0-9a-fA-f]{6}$/',
            'title' => 'required|string|max:255',
            'description' => '',
            'frequency' => [
                'required',
                Rule::in(['everyday'])
            ],
            'startHour' => 'date_format:H:i',
            'endHour' => 'date_format:H:i|after:startHour'
        ]);
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Habit  $habit
     * @return \Illuminate\Http\Response
     */
    public function show(Habit $habit)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \App\Http\Requests\UpdateHabitRequest  $request
     * @param  \App\Models\Habit  $habit
     * @return \Illuminate\Http\Response
     */
    public function update(UpdateHabitRequest $request, Habit $habit)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Habit  $habit
     * @return \Illuminate\Http\Response
     */
    public function destroy(Habit $habit)
    {
        //
    }
}
