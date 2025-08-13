import pandas as pd


def find_covid_recovery_patients(patients: pd.DataFrame, covid_tests: pd.DataFrame) -> pd.DataFrame:
    patient2tests = {}
    for line in covid_tests.itertuples():
        pid, result, test_date = line.patient_id, line.result, line.test_date
        if result == "Positive" and pid not in patient2tests:
            patient2tests[pid] = [test_date]
        elif result == "Negative" and len(patient2tests.get(pid, [])) == 1:
            patient2tests[pid].append(test_date)
    res_df = []
    for k, v in patient2tests.items():
        if len(v) < 2:
            continue
        res_df.append({"patient_id": k, "recovery_time": (pd.to_datetime(v[1]) - pd.to_datetime(v[0])).days})
    res_df = pd.DataFrame(res_df).merge(patients, on="patient_id").sort_values(by=["recovery_time", "patient_name"])
    return res_df[["patient_id", "patient_name", "age", "recovery_time"]]
