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
    public function index(Request $request)
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

        DayMark::create($validated);

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

    /**
     * Update the specified resource in storage.
     *
     * @param  \App\Http\Requests\UpdateDayMarkRequest  $request
     * @param  \App\Models\DayMark  $dayMark
     * @return \Illuminate\Http\Response
     */
    public function update(UpdateDayMarkRequest $request, DayMark $dayMark)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\DayMark  $dayMark
     * @return \Illuminate\Http\Response
     */
    public function destroy(DayMark $dayMark)
    {
        //
    }
}
