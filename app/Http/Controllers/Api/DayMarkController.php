<?php

namespace App\Http\Controllers\Api;

use App\Http\Controllers\Controller;
use App\Models\DayMark;
use App\Http\Requests\StoreDayMarkRequest;
use App\Http\Requests\UpdateDayMarkRequest;
use App\Http\Resources\DayMarkResource;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Log;

class DayMarkController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index(Request $request) //LEGACY STRUGGLE
    {
        $request->validate([
            'date' => 'required|date'
        ]);

        $dateString = $request->input('date');
        $date = date('Y-m-d',strtotime($dateString));

        $dateMarks = DayMark::with('habit')->whereDate('mark_date','=',$date)->get()->toArray();   //->where('user_id',$request->user()->id)
        $authorizedDateMarks = array_filter($dateMarks,function ($el) use ($request) {
            return $el['habit']['user_id'] === $request->user()->id;
        });

        return DayMarkResource::collection(DayMark::hydrate($authorizedDateMarks));
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \App\Http\Requests\StoreDayMarkRequest  $request
     * @return \Illuminate\Http\Response
     */
    public function store(StoreDayMarkRequest $request)
    {
        $validated = $request->validated();

        Log::info($validated);

        $dateString = $validated['mark_date'];
        $date = date('Y-m-d',strtotime($dateString));

        $markOfThisDay = DayMark::whereDate('mark_date','=',$date)->where('habit_id',$validated['habit_id'])->first();
        if(!$markOfThisDay){
            DayMark::create($validated);
            $validated['updated'] = false;
        } else {
            Log::info($markOfThisDay);
            $markOfThisDay->update($validated);
            $validated['updated'] = true;
        }

        return response()->json($validated);
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\DayMark  $dayMark
     * @return \Illuminate\Http\Response
     */
    public function show(DayMark $dayMark)
    {
        //
    }
}
