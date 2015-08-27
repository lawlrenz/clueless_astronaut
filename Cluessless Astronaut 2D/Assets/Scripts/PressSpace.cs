using UnityEngine;
using System.Collections;

public class PressSpace : MonoBehaviour {
	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown ("space")) {
			GetComponent<playerController>().setActive();
		}
	}
}
